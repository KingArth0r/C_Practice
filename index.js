function updateProgressBar(folderName, totalExercises) {
    const fillElement = document.getElementById(`${folderName}-fill`);
    const labelElement = document.getElementById(`${folderName}-label`);

    const completedExercises = Math.floor(Math.random() * totalExercises) + 1;

    const percentage = (completedExercises / totalExercises) * 100;

    fillElement.style.width = `${percentage}%`;
    labelElement.innerText = `${completedExercises}/${totalExercises} (${percentage.toFixed(2)}%)`;
}

updateProgressBar('basic_exercises', 157);
updateProgressBar('basic_algorithm', 75);
updateProgressBar('tpyes', 18);
updateProgressBar('input_output', 10);
updateProgressBar('for_loop', 61);