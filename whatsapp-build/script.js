const cont_lists_ele = document.getElementById('lp_contact_lists');
const rp_header_img = document.getElementById('rp_header_img');
const rp_header_cont_name = document.getElementById('rp_header_cont_name');
let cont_lists = "";
let filtered_list = {...cont_msg};
let n = 14; //No. of contact; n = list_dp.length, also works
let pre_ele;

function clear_style(ele) {
    ele.style.backgroundColor = '';
}

function darken_color(e)  {
    e.style.backgroundColor = 'rgb(233, 233, 233)';
    if (pre_ele) {
        clear_style(pre_ele);
    }
    pre_ele = e;
}

function change_rp_content(name, img_src) {
    /* rp_header_img.attributes[2].nodeValue = "./Images/contact_dp_images/cont_dp_biden.jpg"; */
    rp_header_img.setAttribute('src',`./Images/contact_dp_images/${img_src}.jpg`);
    rp_header_cont_name.innerHTML = name;
}

function msg_you(msg_text, msg_sr) {
    //msg_sr stands for msg_sender_receiver
    return `
    <div class="rp_msg_design ${msg_sr}">
        ${msg_text}
    </div>
    `;
}

function srh_by_query(e) {
    filtered_list = {};
    for (let i = 0; i < n; i++) {
        if (list_names[i].toLowerCase().startsWith(e.value)) {
            filtered_list[list_names[i]] = 0;
        } 
    }
    cont_lists = select_cont_list(filtered_list);
    render_cont_list(cont_lists);
}

function selected_cont(e) {
    darken_color(e);
    change_rp_content(e.getAttribute('id'), e.getAttribute('data-img-src'));
}

function crt_cont_ele(img_src, cont_name, rec_msg) {
    return `
    <div onclick="selected_cont(this)" class="lp_contact_list"
    data-img-src=${img_src} id="${cont_name}">
        <img class="lp_contact_dp" 
        src="./Images/contact_dp_images/${img_src}.jpg"  alt="" />
        <div class="lp_contact_details">
            <h3>${cont_name}</h3>
            <p>${rec_msg}</p>
        </div>
    </div>
    `;
}

function render_cont_list(content) {
    cont_lists_ele.innerHTML = content;
}

function select_cont_list(filtered_list) {
    cont_lists = ""
    for (let i = 0; i < n; i++) {
        if (list_names[i] in filtered_list) {
            cont_lists = cont_lists + 
            crt_cont_ele(list_dp[i], list_names[i], recent_msg[i]);
        }
    }
    return cont_lists;
}

cont_lists = select_cont_list(filtered_list);
render_cont_list(cont_lists);
selected_cont(document.getElementById(list_names[0]));

