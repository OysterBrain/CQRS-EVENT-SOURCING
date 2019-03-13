const express = require('express');
const http = require('http');
const url = require('url');
const WebSocket = require('ws');


const app = express();

app.use(function (req, res) {
    res.send({ msg: "hello" });
});

/*app.use(function(req, res, next) {
    res.header('Access-Control-Allow-Origin', '*');
    res.header('Access-Control-Allow-Methods', 'POST, GET, OPTIONS');
    res.header('Access-Control-Allow-Headers', 'Content-Type');
    console.log("heeeee")
    res.send({ msg: "hello" });
    return next();
});*/

const server = http.createServer(app);

server.listen(808, function listening() {
    console.log('En écoute sur le port %d', server.address().port);
});

const wss = new WebSocket.Server({ server });

var arrayClient=[]

wss.on('connection', function connection(ws, req) {
    //const location = url.parse(req.url, true);
    console.log('New request %s', url.parse(req.url, true).query.pseudo);
    // You might use location.query.access_token to authenticate or share sessions
    // or req.headers.cookie (see http://stackoverflow.com/a/16395220/151312)
    arrayClient.push(url.parse(req.url, true).query.pseudo)

    wss.clients.forEach(function each(client) {
        // Rediffuser seulement aux autres et seulement si la websocket est encore ouverte
        if (client.readyState === WebSocket.OPEN) {
            // On envoi les données en json puisqu'il n'est pas possible de faire transiter des objets complexes.
            client.send(JSON.stringify({type:'users', data: arrayClient}));
        }
    });

    ws.on('message', function incoming(data) {
        // On récupère le pseudo de l'emeteur
        const emetteur = url.parse(req.url, true).query.pseudo
        console.log('New data %s', data);
        console.log('Nouveau message de %s : %s', emetteur, data);

        // Pour chaque message reçu, nous le rediffusons aux autres
        wss.clients.forEach(function each(client) {
            // Rediffuser seulement aux autres et seulement si la websocket est encore ouverte
            if (client.readyState === WebSocket.OPEN) {
                // On envoi les données en json puisqu'il n'est pas possible de faire transiter des objets complexes.
                client.send(JSON.stringify({emetteur: emetteur, texte: data}));
            }
        });
    });

    ws.on('close', function close() {
        console.log(arrayClient);
        const index = arrayClient.indexOf(url.parse(req.url, true).query.pseudo);
        if (index !== -1) {
            arrayClient.splice(index, 1);
        }
        console.log('client disconnected %s',arrayClient);
        console.log(arrayClient);

        wss.clients.forEach(function each(client) {
            // Rediffuser seulement aux autres et seulement si la websocket est encore ouverte
            if (client.readyState === WebSocket.OPEN) {
                // On envoi les données en json puisqu'il n'est pas possible de faire transiter des objets complexes.
                client.send(JSON.stringify({type:'users', data: arrayClient}));
            }
        });
    });

});





