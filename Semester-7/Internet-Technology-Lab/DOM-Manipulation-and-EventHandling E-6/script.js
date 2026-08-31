// Get the student name element
let studentName = document.getElementById("studentName");

// Get the name input
let nameInput = document.getElementById("nameInput");

// Get the About section
let aboutSection = document.getElementById("aboutSection");

// Get the About text
let aboutText = document.getElementById("aboutText");

// Get the About input
let aboutInput = document.getElementById("aboutInput");

// Get buttons
let nameButton = document.getElementById("nameButton");

let aboutButton = document.getElementById("aboutButton");

let colorButton = document.getElementById("colorButton");

let hideButton = document.getElementById("hideButton");

let darkButton = document.getElementById("darkButton");

// Change Student Name

nameButton.addEventListener("click", function () {
  studentName.textContent = nameInput.value;
});

// Change About Text

aboutButton.addEventListener("click", function () {
  aboutText.textContent = aboutInput.value;
});

// Change Text Color

colorButton.addEventListener("click", function () {
  studentName.style.color = "red";
});

// Hide / Show About Section

hideButton.addEventListener("click", function () {
  if (aboutSection.style.display === "none") {
    aboutSection.style.display = "block";

    hideButton.textContent = "Hide About";
  } else {
    aboutSection.style.display = "none";

    hideButton.textContent = "Show About";
  }
});

// Toggle Dark Mode

darkButton.addEventListener("click", function () {
  document.body.classList.toggle("dark-mode");
});
