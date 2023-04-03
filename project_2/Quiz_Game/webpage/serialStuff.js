//when the user clicks anywhere on the page
// document.addEventListener('click', async () => {
//   // Prompt user to select any serial port.
//   var port = await navigator.serial.requestPort();
//   // be sure to set the baudRate to match the ESP32 code
//   await port.open({ baudRate: 115200 });

//   let decoder = new TextDecoderStream();
//   inputDone = port.readable.pipeTo(decoder.writable);
//   inputStream = decoder.readable;

//   reader = inputStream.getReader();
//   readLoop();

// });


var inputButton = false;
var pins = [0,0,0]

/*score variables*/
var score = 0;

var qCount = 0; 
let questions = ["q1", "ans1", "ans2", "ans3", "ans4"];
var currSelect = 0; 
var correct = 1; 

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
          inputButton = true;
        }
        else{
          inputButton = false;
        }
      }
      selectBox(pins[0], pins[1]);
    }
  }
};

var timeLeft = 30;

var timerID = document.getElementById("time");
timerID = setInterval(countdown, 1000);

/* show score on screen and timer*/
function countdown(){
  if (timeLeft == -1) {
    clearTimeout(timerId);
    // doSomething();
  } else {
    document.getElementById("time").innerText = "Time Left: "+ timeLeft;
    document.getElementById("score").innerText = "Score is " + score;
    timeLeft--;
  }
}


document.getElementById("question").innerText="question";
document.getElementById("btn1").innerText="btn1";
document.getElementById("btn2").innerText="btn2";
document.getElementById("btn3").innerText="btn3";
document.getElementById("btn4").innerText="btn4";
jQuery(function($){

})

/*UPDATE answers
 * questions array
 */
function updateQuestion(){
  document.getElementById("question").innerText=questions[0];
  document.getElementById("btn1").innerText=questions[1];
  document.getElementById("btn2").innerText=questions[2];
  document.getElementById("btn3").innerText=questions[3];
  document.getElementById("btn4").innerText=questions[4];
}


/*int x, int y */
async function selectBox(xVal, yVal){
  /* unselect all */
  let unsel = "btn-outline-secondary";
  let sel = "btn btn-primary btn-lg";

    
  document.getElementById("btn1").toggleClass(unsel);
  document.getElementById("btn2").toggleClass(unsel);
  document.getElementById("btn3").toggleClass(unsel);
  document.getElementById("btn4").toggleClass(unsel);

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

function checkAnswer(){
  if(inputButton || timeLeft == 0){
    if (currSelect == correct){
      score++;
    }
    currSelect = 0; 
    correct = 1; /*value of new correct*/
  }
  qCount++;
  updateQuestion();
}

// updateQuestion();

