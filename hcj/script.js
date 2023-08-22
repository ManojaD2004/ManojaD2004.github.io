const nameEle = document.getElementById("name");
const tweetEle = document.getElementById("tweet");
const root = document.getElementById("root");

function createTweet(name, tweet) {
  return `<div class="tweet">
            <h4>${name}</h4>
            <p>${tweet}</p>
        </div>`;
}

function sendTweet() {
  if (nameEle.value.trim() === "" || tweetEle.value.trim() === "") {
    alert("Name and Tweet cannot be Empty!");
  } else {
    root.innerHTML =
      root.innerHTML + createTweet(nameEle.value, tweetEle.value);
  }
}
