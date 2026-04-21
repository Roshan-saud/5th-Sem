function savePreference() {
    let theme = document.getElementById("themeSelect").value;
    let fontSize = document.getElementById("fontSizeSelect").value;

    // Save to localStorage
    localStorage.setItem("theme", theme);
    localStorage.setItem("fontSize", fontSize);

    applyPreference();
}

function applyPreference() {
    let theme = localStorage.getItem("theme") || "light";
    let fontSize = localStorage.getItem("fontSize") || "16px";

    document.body.className = theme;
    document.getElementById("sampleText").style.fontSize = fontSize;

    // Set selects to current preference
    document.getElementById("themeSelect").value = theme;
    document.getElementById("fontSizeSelect").value = fontSize;
}

function resetPreference() {
    localStorage.removeItem("theme");
    localStorage.removeItem("fontSize");
    applyPreference();
}

