//when the user clicks anywhere on the page
document.addEventListener('click', async () => {
  // Prompt user to select any serial port.
  var port = await navigator.serial.requestPort();
  // be sure to set the baudRate to match the ESP32 code
  await port.open({ baudRate: 115200 });

  let decoder = new TextDecoderStream();
  inputDone = port.readable.pipeTo(decoder.writable);
  inputStream = decoder.readable;

  reader = inputStream.getReader();
  readLoop();

});


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
        counterVal += parseInt(value)/100.0;
        redVal = (1+Math.sin(counterVal)) * (255/2);
        document.body.style.backgroundColor = 'rgb(' + redVal + ',  60, 50)';
      }

    }
  }
};

/*score variables*/
int score[] = {0};
int oldScore[] = {score[0]};

var inputButton = false;

/*TODO: add timer?*/
/*flashes score on led*/
/* change to show score on screen?*/
async function showScore(){
	delay(2000);
	for (int i =0; i<score[0]; i++){
		digitalWrite(leds[0], HIGH);
		delay(500);
		digitalWrite(leds[0], LOW);
		delay(500);
	}
}

/*UPDATE answers
 * questions array
 */
async function updateChoices(questions){
  document.getElementById("btn1").textContent="newtext";
  document.getElementById("btn2").textContent="newtext";
  document.getElementById("btn3").textContent="newtext";
  document.getElementById("btn4").textContent="newtext";
}


/*int x, int y */
async function selectBox(xVal, yVal){
  /* unselect all */
  let unsel = "btn-outline-secondary";
  let sel = "btn btn-primary btn-lg";

  document.getElementById("btn1").className = unsel;
  document.getElementById("btn2").className = unsel;
  document.getElementById("btn3").className = unsel;
  document.getElementById("btn4").className = unsel;

	/*top*/ 
	if(xVal <=511 && xVal > 0){
		/*left*/
		if(yVal <=511 && yVal > 0){
      document.getElementById("btn1").className = sel;
		}
		/*right*/
		if(yVal <=511 && yVal > 0){
      document.getElementById("btn2").className = sel;
		}
	}
	/*bottom */
	if(xVal <=1023 && xVal > 511){
		/*left*/
		if(yVal <=511 && yVal > 0){
      document.getElementById("btn3").className = sel;
		}
		/*right*/
		if(yVal <=511 && yVal > 0){
      document.getElementById("btn4").className = sel;
		}
	}
}

function checkAnswer(){

}

/* when button is pressed select item */
void pressedBtn(int b){
	/**/
	while(digitalRead(btnPin) !=1){
		Serial.println(digitalRead(btnPin));
		delay(500);
		/*print to screen selection*/
	}
	btnPressed = -1;
}

bool compArr(int *arr1, int *arr2, int l){
	for (int j = 0; j<1; j++){
		if (arr1[j]!=arr2[j]){
			return false;
		}
	}
	return true;
}

