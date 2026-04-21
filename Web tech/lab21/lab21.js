function fetchData() {
    let xhr = new XMLHttpRequest();
    xhr.open("GET", "lab21_server.php", true);
    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4 && xhr.status == 200) {
            document.getElementById("result").innerHTML = xhr.responseText;
        }
    };
    xhr.send();
}
