var startModal = document.getElementById("startModal");

var nextModal = document.getElementById("nextModal");
var endModal = document.getElementById("endModal");

let startbtn = document.getElementsByClassName("startbtn")[0];

startbtn.addEventListener('click',function (){
    startModal.classList.remove('active');
});


let currentLevel = 1;
function nextLevel(){
    brick_container.innerHTML = '';
    nextModal.classList.add('active');
    let next = document.querySelector('.next');
    next.addEventListener('click',function ()
    {
        if(currentLevel === 1)
        {
            generateLevelOne();
            ballMoveDelay = 8;
        }
        else if(currentLevel === 2)
        {
            generateLevelTwo();
            ballMoveDelay = 7;
        }
        else if(currentLevel === 3)
        {
            generateLevelThree();
            ballMoveDelay = 6;
        }
        else if(currentLevel === 4)
        {
            generateLevelFour();
            ballMoveDelay = 5;
        }
        else if(currentLevel === 5)
        {
            generateLevelFive();
            ballMoveDelay = 4;
        }
        generatePowers();
        currentLevel++;
        nextModal.classList.remove('active');
        mainContainer = document.querySelector(".main-container")
        pad = document.querySelector("#pad");
        ball = document.querySelector("#ball");
        bricks = document.querySelectorAll(".brick")
        gameRunning = 0;
        padCollisionPoint = 0;
        ballsLife = maxLives;
        timerId = 0;
        ballsDirection = {
            left: 0,
            top: 0
        }
        ballTop = pad.offsetTop - ball.offsetHeight;
        ballLeft = pad.offsetLeft + pad.offsetWidth/2 - ball.offsetWidth/2;
        mainContainer.style.setProperty("--ball-left", ballLeft.toString())
        mainContainer.style.setProperty("--ball-top", ballTop.toString())
        document.getElementById("score").innerText = totalScore.toString()
        document.getElementById("lives").innerText = ballsLife.toString()
        clearInterval(timerId);
    })
}


document.getElementById("score").innerText = totalScore.toString()
document.getElementById("lives").innerText = ballsLife.toString()




