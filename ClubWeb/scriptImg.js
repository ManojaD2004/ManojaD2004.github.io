const imgSCaseL = document.getElementById("imgSCaseL");
const imgSCaseM = document.getElementById("imgSCaseM");
const imgSCaseR = document.getElementById("imgSCaseR");
const imgSCButs = document.getElementById("imgSCButtons");
const imgsButsClearUp= [];

let imgButton = "";
let groupButton = "";

for (let i = 0; i < 10; i++) {
    imgButton = '<button data-img-no="' + i;
    imgButton = imgButton + '"class="circleButton"' + 
    'onclick="imgButtonChange(this)"></button>';
    groupButton = groupButton + imgButton;
    imgButton = "";
}

imgSCButs.innerHTML = groupButton;

const imgGallery = {0: "gold",
1: "red",
2: "yellow",
3: "green",
4: "blue", 
5: "cyan",
6: "purple",
7: "lime",
8: "brown",
9: "pink"}

const imgNoRef = {0: "0 - zero",
1: "1 - one",
2: "2 - two",
3: "3 - three",
4: "4 - four", 
5: "5 - five",
6: "6 - six",
7: "7 - seven",
8: "8 - eight",
9: "9 - nine"}

let counter = 1

function imgSCaseChange() {

    if (counter === -1) {
        counter = 9;
    }
    else if (counter === 10) {
        counter = 0;
    }

imgSCaseM.style.backgroundColor = imgGallery[counter];
imgSCaseM.innerHTML = imgNoRef[counter];

let counterL = counter - 1;
    if (counterL === -1){
        counterL = 9;
    }

imgSCaseL.style.backgroundColor = imgGallery[counterL];
imgSCaseL.innerHTML = imgNoRef[counterL];

let counterR = counter + 1;
    if (counterR === 10){
        counterR = 0;
    }

imgSCaseR.style.backgroundColor = imgGallery[counterR];
imgSCaseR.innerHTML = imgNoRef[counterR];


}

function imgSCaseLFun() {
    imgSCaseR.style.backgroundColor = "red";
    counter = counter - 1;
    imgSCaseChange();
}

function imgSCaseRFun() {
    imgSCaseR.style.backgroundColor = "red";
    counter = counter + 1;
    imgSCaseChange();
}

imgSCaseChange();

function imgButtonChange(selectedButton) {
    let counterNo = selectedButton.getAttribute("data-img-no");
    selectedButton.style.backgroundColor = 'rgb(14, 2, 34)';
    for (let i = 0; i < imgsButsClearUp.length; i++) {
        imgsButsClearUp[i].style.backgroundColor = 'rgb(122, 66, 212)';
        imgsButsClearUp.shift();
    }
    imgsButsClearUp.push(selectedButton);
    counter = parseInt(counterNo);
    imgSCaseChange();
}

