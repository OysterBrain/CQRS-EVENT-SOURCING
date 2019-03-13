
var ChatClientManager = function () {

    var pseudo ="pseudo ";

    if (document.cookie == "") {
        person = prompt("Entre ton pseudo !", "");

        document.cookie =pseudo ;

        console.log(document.cookie);
    } else {
        pseudo = document.cookie;

        console.log(document.cookie);
    }



    // Connexion de la websocket au serveur
    // Contrairement à la partie serveur, les navigateurs modernes embarquent nativement de quoi se connecter à des websocket
    // https://developer.mozilla.org/fr/docs/WebSockets

    this.ws = new WebSocket(`ws://127.0.0.1:8080/chat?pseudo=${pseudo}`, 'http');

    this.ws.addEventListener("open", evt => {
        console.log(evt)
        this.fireEvent("welcome", JSON.stringify({evt:'welcome', data: `<p>${this.getTimeHtmlFormat()} <i>Vous venez de vous connecter.</i></p>`}));
        //$("#chat-body").append(`<p>${this.getTimeHtmlFormat()} <i>Vous venez de vous connecter.</i></p>`);
    });

    this.ws.addEventListener("message", evt => {
        const data = JSON.parse(evt.data);
        if(data.type=='users'){
            this.fireEvent("users", JSON.stringify({evt:'users', data: data.data}));
        }
        else {
            console.log('[onMessageListener] Nouveau message', data);
            this.fireEvent("message", JSON.stringify({evt:'users', data: `<p>${this.getTimeHtmlFormat()} <b>${data.emetteur}</b> : ${data.texte}</p>`}));
            //$("#chat-body").append(`<p>${this.getTimeHtmlFormat()} <b>${data.emetteur}</b> : ${data.texte}</p>`);
        }
    });

    this.dummy = document.createElement('dummy');

    this.on = function(event, func){this.dummy.addEventListener(event, func);};
    //this.ws.onclose = () => console.log('La WebSocket vient d\être fermée.');
    //this.ws.onerror = (erreur) => console.log('WebSocket error');

}

ChatClientManager.prototype.fireEvent = function(event, obj){
    this.dummy.dispatchEvent(new CustomEvent(event, {detail: obj}));
}

ChatClientManager.prototype.getTimeHtmlFormat = function () {
    const date = new Date();
    return `<span class="badge">${date.getHours()}:${date.getMinutes()}:${date.getSeconds()}</span>`;
}

ChatClientManager.prototype.envoyerMessage = function (message) {
    try {
        if (message) {
            this.ws.send(message);
        }
    } catch (e) {
        console.error(e);
    }
}


var ChatClient = (function () {

    function Singleton() {
        this.chatClient = new ChatClientManager()
    }

    var instance;
    return {
        getInstance: function () {
            if (null == instance) {
                instance = new Singleton();
                instance.constructor = null; // Note how the constructor is hidden to prevent instantiation
            }
            return instance.chatClient; //return the singleton instance
        }
    };
})();