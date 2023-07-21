const list_img = ['https://img.icons8.com/ios-filled/50/menu--v1.png',
'https://img.icons8.com/ios-filled/50/home.png',
'https://img.icons8.com/external-anggara-glyph-anggara-putra/64/external-reels-video-social-media-interface-anggara-glyph-anggara-putra.png',
'https://img.icons8.com/material-rounded/48/subscription.png',
'https://img.icons8.com/ios-filled/50/library.png'
];

const list_icon_name = ['Menu', 'Home', 'Shorts', 
'Subscription', 'Library'];

let content = '';
let element = '';

for (let index = 0; index < 5; index++) {
    element = `<div class="icon1">
    <img class="icon2"
    src=${list_img[index]} />
    <p class="icon-text">${list_icon_name[index]}</p>
</div>`;
content = content + element;
}
console.log(content);

document.getElementById('box1').innerHTML = content;
