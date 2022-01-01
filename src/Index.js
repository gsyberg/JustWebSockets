jw = {}
jw.socket = null;

function output(message)
{
    let field = document.getElementById("output");

    field.innerHTML = "- " + message + "\n" + field.innerHTML;
}

function init()
{
    output("Welcome to Just WebSockets test client.");
}

function connect()
{
    try {
        if (typeof MozWebSocket == 'function')
        {
            WebSocket = MozWebSocket;
        }

        if (jw.socket && jw.socket.readyState === 1 )
        {
            jw.socket.close();
        }

        let host = document.getElementById("host").value;
        let port = document.getElementById("port").value;
        let url = "wss://" + host + ":" + port;  

        jw.socket = new WebSocket(url);

        jw.socket.onopen = function (evt)
        {
            output("Connected to Just WebSocket server.");
        };

        jw.socket.onclose = function (evt)
        {
            output("Disconnected from Just Websocket server.");
        };

        jw.socket.onmessage = function (evt)
        {
            output("Recieved " + evt.data.length + " bytes over socket.");
            output("Message recieved: " + JSON.parse(evt.data).string);
        };

        jw.socket.onerror = function (evt)
        {
            output("Socket error: " + evt.data);
        };

        let button = document.getElementById("connectButton");
        button.onclick = disconnect;
        button.innerHTML = "Disconnect";

    } catch (exception) {
        output("Exception: " + exception);
    }
}

function disconnect()
{
    if (jw.socket !== null)
    {
        let button = document.getElementById("connectButton");
        button.onclick = connect;
        button.innerHTML = "Connect";

        jw.socket.close()
        jw.socket = null;
    }
}

function send()
{
    if (jw.socket == null)
    {
        output("You are disconnected. Connect before sending a message.");
        return;
    }

    let message = {};
    message.string = document.getElementById("message").value;

    jw.socket.send(JSON.stringify(message));
}

window.onbeforeunload = function(event)
{
    disconnect();
    return null;
};