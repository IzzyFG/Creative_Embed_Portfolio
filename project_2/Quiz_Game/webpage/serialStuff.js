/*quiz info*/
let quizName = 'NULL';
let questionList = new Array(10);

/*question variables*/
var qCount = -1; 
var currSelect = 0; 
var correct = -1; 
let questions = {}; //data[qCount];

/*serial variables */
var inputButton = false;
var pins = [0,0,0]

/*score variables*/
var score = 0;

/*timer*/
var timeLeft = 30;
var timerID = document.getElementById("time");

/* 
 * the first time the user clicks anywhere on the page
 */
document.addEventListener('click', async () => {
  console.log("user click");
  // Prompt user to select any serial port.
  var port = await navigator.serial.requestPort()
  be sure to set the baudRate to match the ESP32 code
  await port.open({ baudRate: 115200 });
  let decoder = new TextDecoderStream();
  inputDone = port.readable.pipeTo(decoder.writable);
  inputStream = decoder.readable;

  reader = inputStream.getReader();
  $('#startModal').modal('hide');
  readLoop();
}, {once : true});

async function readLoop() {
  counterVal = 0;
  while (true) {
    const { value, done } = await reader.read();
    if (done) {
      // Allow the serial port to be closed later.
      console.log("closing connection")
      reader.releaseLock();
      break;
    }
    if (value) {
      parsedVal = parseInt(value);
      if (!isNaN(parsedVal)) {
        pins[counterVal] = parsedVal;
        counterVal += 1;
        if(counterVal == 3 && pins[2] == 1){
          document.getElementById("inpt").click();
        }
        else{
          inputButton = false;
        }
      }
      selectBox(pins[0], pins[1]);
    }
  }
};

/* 
 * select quiz page
 */ 

function newQuiz(){
  document.getElementById("q-content").innerText = "Pick a Trivia Quiz Topic:";
  document.getElementById("btn1").innerText="NYC";
  document.getElementById("btn2").innerText="Music";
  document.getElementById("btn3").innerText="Sports";
  document.getElementById("btn4").innerText="Film";
}

/* 
 * on page load show starter modal
 * call newQuiz
 */ 
window.onload = (event) => {
  $('#startModal').modal('show');
  newQuiz();
};


/* show score on screen and timer*/
function countdown(){
  if (timeLeft == -1) {
    endQuiz();
    clearTimeout(timerID);
    console.log("Timer Ended");
  } else {
    document.getElementById("time").innerText = "Time Left: "+ timeLeft;
    document.getElementById("score").innerText = "Score:" + score;
    timeLeft--;
  }
}

/* 
 * UPDATE answers
 * questions array
 */
function updateQuestion(){
  questions = questionList[++qCount];
  document.getElementById("q-content").innerText=questions.q;
  document.getElementById("btn1").innerText=questions.ansr[0];
  document.getElementById("btn2").innerText=questions.ansr[1];
  document.getElementById("btn3").innerText=questions.ansr[2];
  document.getElementById("btn4").innerText=questions.ansr[3];
  correct = parseInt(questions.correct);
}

/*select quiz*/
function fetchQuiz(){
  fetch(quizName)
  .then(response => response.json())
  .then(data => {
    questionList = data.quiz
    console.log("set quiz")
    updateQuestion()
  })
  .catch(err => console.log(err));
}

/*int x, int y */
function selectBox(xVal, yVal){
  /* unselect all */
  let unsel = "btn btn-outline-secondary";
  let sel = "btn btn-primary";

    
  document.getElementById("btn1").className = unsel;
  document.getElementById("btn2").className = unsel;
  document.getElementById("btn3").className = unsel;
  document.getElementById("btn4").className = unsel;

	/*top*/ 
	if(xVal <=511 && xVal > 0){
		/*left*/
		if(yVal <=511 && yVal > 0){
      document.getElementById("btn1").className = sel;
      currSelect = 1; 
		}
		/*right*/
		if(yVal <=511 && yVal > 0){
      document.getElementById("btn2").className = sel;
      currSelect = 2; 
		}
	}
	/*bottom */
	if(xVal <=1023 && xVal > 511){
		/*left*/
		if(yVal <=511 && yVal > 0){
      document.getElementById("btn3").className = sel;
      currSelect = 3; 
		}
		/*right*/
		if(yVal <=511 && yVal > 0){
      document.getElementById("btn4").className = sel;
      currSelect = 4; 
		}
	}
}

/*
 * start quiz pretty
 */
function startQuiz(){
  quizName = "./quiz"+currSelect+".json";

  /*clear current modal text */
  const element = document.getElementById('modal-text');
  while (element.hasChildNodes()) {
    element.removeChild(element.firstChild);
  }

  const para = document.createElement("h");
  const n1 = document.createTextNode("Quiz starting in ");
  para.appendChild(n1);
  
  const one = document.createElement("h");
  one.setAttribute("style", "inline");
  const n2 = document.createTextNode("3...");
  one.appendChild(n2);

  const two = document.createElement("h");
  two.setAttribute("style", "inline");
  const n3 = document.createTextNode("2...");
  two.appendChild(n3);

  const three = document.createElement("h");
  three.setAttribute("style", "inline");
  const n4 = document.createTextNode("1...");
  three.appendChild(n4);

  const go = document.createElement("h");
  go.setAttribute("style", "inline");
  const n5 = document.createTextNode(" GO!!");
  go.appendChild(n5);
  
  element.appendChild(para);
  $('#startModal').modal('show');

  var sTime = 4; 
  var startTimer = setInterval(function(){
    switch (sTime){
      case 1:
        element.appendChild(go);
        sTime-=1;
        break;
      case 2:
        element.appendChild(three);
        sTime-=1;
        break;
      case 3:
        element.appendChild(two);
        sTime-=1;
        break;
      case 4:
        element.appendChild(one);
        sTime-=1;
        break;
      default:
        clearInterval(startTimer);
        $('#startModal').modal('hide');
    }
  }, 1000);


  timerID = setInterval(countdown, 1000);
  fetchQuiz();
}

/* 
 * timer == 0 or no more questions
 */
function endQuiz(){
  var temp = 29 - timeLeft;
  const para = document.createElement("p");
  const node = document.createTextNode("Finished in "+timeLeft +" seconds with a score of " + score);
  para.appendChild(node);

  const element = document.getElementById('modal-text');
  while (element.hasChildNodes()) {
    element.removeChild(element.firstChild);
  }
  element.appendChild(para);

  document.getElementById("reset-btn").className ="btn btn-primary";

  $('#startModal').modal('show');
}

/* 
 * modified exponential falloff function to create score
 * and account for time
 * less time to answer == more points
 */
function updateScore(){
  /* 0<= time passed <31*/
  /* update element only if score updated*/
  var currTime = 30 - timeLeft;
  if (-1<currTime<31){ 
    var temp = Math.pow(301, (currTime/100));
    score+= -1 + (301/temp);
    document.getElementById("score").innerText = "Score: " + score;
  }
}
/* 
 * checks answer when: 
 * timeLeft = 0
 * answer selected on button press
 * if questions left 
 * - then update questions
 * - else end quiz 
 */
function checkAnswer(){
  if(inputButton || timeLeft == 0){
    if (currSelect == correct){
      updateScore();
    }
    currSelect = 0; 
    correct = 1; /*value of new correct*/
  }
  if (qCount >9 || timeLeft == 0){
    endQuiz();
  }
  else{
    updateQuestion();
  }
}



/* physical button has been clicked */
document.getElementById("inpt").onclick = function(){
  console.log("button has been clicked");
  inputButton = true;

  /*check if quiz has been selected*/
  if(quizName.localeCompare('NULL') == 0){
    startQuiz();
  }
  else{
    checkAnswer();
  }

}

/*
 * Reset Quiz
 */
document.getElementById("reset-btn").onclick = function(){
  quizName = 'NULL';
  qCount = -1
  currSelect = 0;
  correct = -1;
  inputButton = false;
  score = 0;
  timeLeft = 30;

  document.getElementById("time").innerText = "";
  document.getElementById("score").innerText = "";
  document.getElementById("reset-btn").className = "btn btn-primary invisible";
  $('#startModal').modal('hide');
  
  function delay(time) {
    return new Promise(resolve => setTimeout(resolve, time));
  }
  
  delay(2000).then(() => newQuiz());
}
