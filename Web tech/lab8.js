// Dialog boxes
alert("Welcome to JavaScript Lab");

let confirmBox = confirm("Do you want to continue?");
let name = prompt("Enter your name:");
console.log(name);

// Change title color
function changeColor() {
    document.getElementById("heading").style.color = "red";
}

function resetColor() {
    document.getElementById("heading").style.color = "black";
}

// Modify list using DOM
function modifyList() {
    let itemsByClass = document.getElementsByClassName("item");
    let itemsByTag = document.getElementsByTagName("li");

    for (let i = 0; i < itemsByClass.length; i++) {
        itemsByClass[i].innerHTML = "Updated Item " + (i + 1);
    }

    // Example using getElementById
    document.getElementById("myList").style.backgroundColor = "lightgray";
}
