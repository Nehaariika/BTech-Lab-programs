/* Select the form and HTML elements */

let form = document.getElementById("registrationForm");

let nameInput = document.getElementById("name");

let emailInput = document.getElementById("email");

let passwordInput = document.getElementById("password");

let ageInput = document.getElementById("age");

let genderInput = document.getElementById("gender");

let departmentInput = document.getElementById("department");

let message = document.getElementById("message");

let welcomeMessage = document.getElementById("welcomeMessage");

let clearDataButton = document.getElementById("clearDataButton");

let resetButton = document.getElementById("resetButton");

/* Display welcome message from saved data */

let savedName = localStorage.getItem("studentName");

if (savedName !== null) {
  welcomeMessage.textContent = "Welcome back, " + savedName + "!";
}

/* Form Submission */

form.addEventListener("submit", function (event) {
  // Prevent normal form submission
  event.preventDefault();

  // Read form values
  let name = nameInput.value.trim();

  let email = emailInput.value.trim();

  let password = passwordInput.value;

  let age = Number(ageInput.value);

  let gender = genderInput.value;

  let department = departmentInput.value;

  // Clear previous error messages
  document.getElementById("nameError").textContent = "";

  document.getElementById("emailError").textContent = "";

  document.getElementById("passwordError").textContent = "";

  document.getElementById("ageError").textContent = "";

  document.getElementById("genderError").textContent = "";

  document.getElementById("departmentError").textContent = "";

  message.textContent = "";

  // Validation flag
  let isValid = true;

  // Validate name
  if (name === "") {
    document.getElementById("nameError").textContent = "Name cannot be empty.";

    isValid = false;
  }

  // Validate email
  let emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;

  if (!emailPattern.test(email)) {
    document.getElementById("emailError").textContent =
      "Please enter a valid email address.";

    isValid = false;
  }

  // Validate password
  if (password.length < 8) {
    document.getElementById("passwordError").textContent =
      "Password must contain at least 8 characters.";

    isValid = false;
  }

  // Validate age
  if (
    ageInput.value.trim() === "" ||
    !Number.isInteger(age) ||
    age < 16 ||
    age > 100
  ) {
    document.getElementById("ageError").textContent =
      "Please enter a valid age between 16 and 100.";

    isValid = false;
  }

  // Validate gender
  if (gender === "") {
    document.getElementById("genderError").textContent =
      "Please select your gender.";

    isValid = false;
  }

  // Validate department
  if (department === "") {
    document.getElementById("departmentError").textContent =
      "Please select your department.";

    isValid = false;
  }

  // Stop if validation fails
  if (!isValid) {
    message.textContent = "Please correct the errors in the form.";

    message.style.color = "red";

    return;
  }

  // Save only non-sensitive information
  localStorage.setItem("studentName", name);

  localStorage.setItem("studentEmail", email);

  localStorage.setItem("studentAge", String(age));

  localStorage.setItem("studentGender", gender);

  localStorage.setItem("studentDepartment", department);

  // Display success message
  message.textContent =
    "Registration successful! Your information has been saved.";

  message.style.color = "green";

  welcomeMessage.textContent = "Welcome, " + name + "!";
});

/* Clear the form fields */

resetButton.addEventListener("click", function () {
  message.textContent = "";

  document.getElementById("nameError").textContent = "";

  document.getElementById("emailError").textContent = "";

  document.getElementById("passwordError").textContent = "";

  document.getElementById("ageError").textContent = "";

  document.getElementById("genderError").textContent = "";

  document.getElementById("departmentError").textContent = "";
});

/* Remove saved student information */

clearDataButton.addEventListener("click", function () {
  localStorage.removeItem("studentName");

  localStorage.removeItem("studentEmail");

  localStorage.removeItem("studentAge");

  localStorage.removeItem("studentGender");

  localStorage.removeItem("studentDepartment");

  welcomeMessage.textContent = "";

  message.textContent = "Saved student data has been cleared.";

  message.style.color = "green";
});
