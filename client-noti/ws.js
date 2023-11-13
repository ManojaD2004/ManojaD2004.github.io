console.log("Service Worker Loaded");

self.addEventListener("push", (e) => {
  const data = e.data;
  console.log("Push Reciveddd...");
  console.log(data.text());
  const data1 = data.json();
  console.log(data1);
  self.registration.showNotification(data1.title, {
    body: data1.des,
    icon: "https://upload.wikimedia.org/wikipedia/commons/e/e8/Tesla_logo.png",
  });
});
