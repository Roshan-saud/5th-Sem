function drawNumbers() {
    let table = document.getElementById("numberTable");
    let rows = table.rows;

    for (let i = 0; i < rows.length; i++) {
        let cells = rows[i].cells;
        for (let j = 0; j < cells.length; j++) {
            cells[j].innerHTML = Math.floor(Math.random() * 100); // Random number 0-99
        }
    }
}
