function updateProgressBar(folderName, totalExercises) {
    const fillElement = document.getElementById(`${folderName}-fill`);
    const labelElement = document.getElementById(`${folderName}-label`);

    // Simulate the number of exercises completed (you can replace this with actual logic)
    const completedExercises = Math.floor(Math.random() * totalExercises) + 1;

    // Calculate percentage
    const percentage = (completedExercises / totalExercises) * 100;

    // Update progress bar
    fillElement.style.width = `${percentage}%`;
    labelElement.innerText = `${completedExercises}/${totalExercises} (${percentage.toFixed(2)}%)`;
}

// Update progress bars for each topic
updateProgressBar('basic-exercises', 157);