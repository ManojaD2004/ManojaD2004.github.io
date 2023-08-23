// js code
let MyUserName = 'MyName';
let MyPassword = 'MyPassword';
//Your name and your password


function verifUser() {
    let username = document.getElementById('username').value;
    let password = document.getElementById('password').value;
    if (username===MyUserName) {
        if (password===MyPassword)  {
            alert('Welcome to Twitter "' + username + '"')
        }
        else {
            alert('The username and Password does not match')
        }
    }
    else {
        alert('This Username "' + username + '" does not exits')
    }
}

function forgetPass() {
    let username = document.getElementById('username').value;
    //Your name and your password
    if (username===MyUserName) {
        alert('The Reset Password link has been sent to your given Mail!')
    }
    else {
        alert('This Username "' + username + '" does not exits')
    }
}

function signInWith(account) {
    let content = '<h1>' + account + ' Login</h1>';
    // alert(content);
    document.getElementById('popUp').innerHTML = content;
    document.getElementById('popUp').style.display = 'inline';
}

function closePopUP() {
    document.getElementById('popUp').style.display = 'none';
}