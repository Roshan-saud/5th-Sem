// Get elements
let title = document.getElementById("title");
let box = document.getElementById("box");

// Mouse enter and leave for title
title.addEventListener("mouseenter", function() {
    title.style.color = "red";
});

title.addEventListener("mouseleave", function() {
    title.style.color = "black";
});

// Mouse enter and leave for box
box.addEventListener("mouseenter", function() {
    box.style.backgroundColor = "green";
    box.innerHTML = "Mouse is over!";
});

box.addEventListener("mouseleave", function() {
    box.style.backgroundColor = "lightblue";
    box.innerHTML = "Mouse over this box";
});
