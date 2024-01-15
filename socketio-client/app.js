const socket = io("https://socket-io-learn-production.up.railway.app", {
  withCredentials: true,
});
let time, newTime;

socket.on("message", (text) => {
  if (time !== null && time !== undefined) {
    newTime = Date.now();
    console.log(`It Took ${(newTime - time) / 1000}`);
  }
  const el = document.createElement("li");
  el.innerHTML = text;
  document.querySelector("ul").appendChild(el);
});

document.querySelector("button").onclick = () => {
  time = Date.now();
  const text = document.querySelector("input").value;
  socket.emit("message", text);
};

// Regular Websockets

// const socket = new WebSocket('ws://localhost:8080');

// // Listen for messages
// socket.onmessage = ({ data }) => {
//     console.log('Message from server ', data);
// };

// document.querySelector('button').onclick = () => {
//     socket.send('hello');
// }
