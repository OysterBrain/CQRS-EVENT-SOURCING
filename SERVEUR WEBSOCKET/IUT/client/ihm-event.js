
//Event pour bouton envoyer

$("#boutonEnvoyer").on("click", function() {
    try {
        const text = $('#messageText').val();
        ChatClient.getInstance().envoyerMessage(text);
        // L'input est vidée de son texte une fois le message envoyé
        $("#messageText").val('');
        return false; // Retourner false pour éviter que la page se recharge
    } catch (e) {
        console.error(e);
        }
    }
);

$('#messageText').keypress(function(e) {
    // Ne réagir que sur la touche Entrée
    if(e.which == 13) {
        const text = $('#messageText').val();
        ChatClient.getInstance().envoyerMessage(text);
        // L'input est vidée de son texte une fois le message envoyé
        $("#messageText").val('');
    }
});

ChatClient.getInstance().on("users", function(e){
    const dataEvent = JSON.parse(e.detail);
    $("#users-list").empty();
    for (user in dataEvent.data)
        $("#users-list").append(`<p>${dataEvent.data[user]}</p>`);
}
);

ChatClient.getInstance().on("welcome", function(e){
        const dataEvent = JSON.parse(e.detail);
        $("#chat-body").append(dataEvent.data);
    }
);

ChatClient.getInstance().on("message", function(e){
        const dataEvent = JSON.parse(e.detail);
        $("#chat-body").append(dataEvent.data);
    }
);

