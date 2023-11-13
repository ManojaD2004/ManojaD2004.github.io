const PUB_KEYS =
  "BBU1t9eB2t85ZBlOckZv_rwrMzZojfKiAwlFGfglpTVIV9ZTIpDytu8zZuDZhVUXv0BVuEg-MXzhi4S4K2SaMes";

// Register SW, Reg Push, Send Push
async function send() {
  // Registering SW
  console.log("Registering Service Worker lol...");
  const register = await navigator.serviceWorker.register("./ws.js", {
    scope: "./client-noti",
  });
  console.log("Registered Service Worker...");

  //   Register Push
  console.log("Registering Push...");
  const subscription = await register.pushManager.subscribe({
    userVisibleOnly: true,
    applicationServerKey: PUB_KEYS,
  });
  console.log("Regesitered Push...");
  //  console.log(subscription);

  //   Send Push Notification
  console.log("Sending Push...");
  // await fetch("/subscribe", {
  //   method: "POST",
  //   body: JSON.stringify(subscription),
  //   headers: { "Content-Type": "application/json" },
  // });
  // console.log("Push Send");
  document.getElementById('demo').innerHTML = JSON.stringify(subscription);
}

if ("serviceWorker" in navigator) {
  send().catch((err) => console.log(err));
}
