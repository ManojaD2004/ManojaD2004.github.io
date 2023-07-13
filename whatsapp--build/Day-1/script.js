import {list} from "./db.js";
console.log(list);
function hello() {
    console.log(list);
    list.push(90);
}
window.hello = hello;