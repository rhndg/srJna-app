# srJna-app
app for better learning
# Requirement
Currently the app only supports resolution of 1366x768.
It will not work propperly for other resolutions.
# Schemes (.gme)
Each scheme governs the flow of the app in each section.
There is a *.gme file for each subject.

##Structure of a *.gme file
The first two names are respectivly the
* Normal background
* MCQ background
The rest of the file is a list of specifications each corresponding to a slide.
* Name of file (background image file)
* cordinates of the button to go to the next slide
* 1 if it is an mcq, 0 otherwise
* (1-4) the correct answer if it is an mcq

#Logger
The app logs how much time (in seconds) the student spent on each question and the score of the student in the log folder.