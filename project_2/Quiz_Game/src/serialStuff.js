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


/*

you also need this code on the ESP32. 
change the code for whichever pin your button is on
note that some pins don't work when connected to web serial

-----

#define BUTTON 35

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON, INPUT);
}

void loop() {
  Serial.print(digitalRead(BUTTON));
  delay(100);
}

*/

/*UPDATE answers
 * questions array
 */
function updateChoices(questions){
  document.getElementById("btn1").textContent="newtext";
  document.getElementById("btn2").textContent="newtext";
  document.getElementById("btn3").textContent="newtext";
  document.getElementById("btn4").textContent="newtext";
}

var inputButton = false;

/*int x, int y */
function selectBox(xVal, yVal){
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
			//box2
		}
	}
	/*bottom */
	if(xVal <=1023 && xVal > 511){
		/*left*/
		if(yVal <=511 && yVal > 0){
			//box3
		}
		/*right*/
		if(yVal <=511 && yVal > 0){
			//box4 
			
		}
	}
}

function checkAnswer(){

}