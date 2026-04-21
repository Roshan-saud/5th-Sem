function getData() {
    fetch('data15.xml')
    .then(response => response.text())
    .then(data => {
        let parser = new DOMParser();
        let xml = parser.parseFromString(data, "text/xml");
        let items = xml.getElementsByTagName("item");
        let output = "<ul>";

        for (let i = 0; i < items.length; i++) {
            let name = items[i].getElementsByTagName("name")[0].textContent;
            let value = items[i].getElementsByTagName("value")[0].textContent;
            output += `<li>${name}: ${value}</li>`;
        }
        output += "</ul>";
        document.getElementById("result").innerHTML = output;
    })
    .catch(error => console.log("Error:", error));
}
