const list_dp = ['cont_dp_mark','cont_dp_altman',
'cont_dp_beast','cont_dp_amber','cont_dp_ambani','cont_dp_bezos',
'cont_dp_biden','cont_dp_grp_nasa','cont_dp_grp_opneai',
'cont_dp_grp_tesla','cont_dp_jack','cont_dp_jackma','cont_dp_leo',
'cont_dp_trump'];

const list_names = ['Mark Zuck', 'Sam Altman', 'Mr Beast', 'Amber Heard',
'Mukesh Ambani','Amazon Bezos','President Biden','NASA 🚀','Open Ai 🤖',
'Tesla 🚘','Jack Twitter','Alibaba Jack Ma','Actor Leonardo Dicaprio',
'Papa Trump'];

const recent_msg = ['Zuck: How is Threads','AI Bro','Beast: Daddy Elon',
'Amber: Can you help me?','...','Rockets incoming',
'How are you still the President',
'CEO: Next Launch on friday!','Sam: ChatGPT 6 is game Changer!!!',
'Elon: Get back to work guys!','Jack: Web 5 is coming bro.',
'How did you even become a Billionaire bro?','Be Brand Ambasidor of our products'
,'I Love Rockets!'];

function clear_style(eles) {
    for (let i = 0; i < eles.length; i++) {
        eles[i].style.backgroundColor = '';
    }
}

function darken_color(e)  {
    const elements_to_clear = document.getElementsByClassName("lp_contact_list");
    clear_style(elements_to_clear);
    e.style.backgroundColor = 'rgb(233, 233, 233)';
}

const cont_lists_ele = document.getElementById('lp_contact_lists');
let cont_lists = "";
let cont_list = ``;
let n = 14; //No. of contact lists

for (let i = 0; i < n; i++) {
    cont_list =`<div onclick="darken_color(this)" class="lp_contact_list">
          <img class="lp_contact_dp" 
          src="./Images/contact_dp_images/${list_dp[i]}.jpg"
          alt="" />
          <div class="lp_contact_details">
            <h3 id="demo">${list_names[i]}</h3>
            <p>${recent_msg[i]}</p>
          </div>
        </div>`;
    cont_lists = cont_lists + cont_list;
}

cont_lists_ele.innerHTML = cont_lists;

