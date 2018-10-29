package project2;


public class Encoder {
	//this string hold the key
	private  String key="";

	public Encoder(String string) {
		//key given stores it in key
		key=string;
	}

	public  Encoder() {
		//randomgen is randomly made key that returns a string
		key=randomgen();

	}
	
	public static String alphabet() {
		//this sets alphabet and returns it as a string 
		String alphabet= "";
		for(char c='a'; c<='z'; c++) {
			alphabet+=c;
		}
		return alphabet;
	}

	public static String randomgen() {
		//this gives a random key  

		//this gets the string of alphabet function
		String alphabet=alphabet();

		//this sets alphabet string to a char array
		char [] alphabetChar=alphabet.toCharArray();

		//holds the key as a char array with length of the alphabet(26)
		char[] key= new char[alphabet.length()];

		//postionHolder saves the the random number generated to in array
		//it allows us to check every box of the array for the random number generated
		// not to be repeated and saved 
		int[] postionHolder= new int[alphabet.length()+1];

		//this initializes postionHolder to -1 since there can be a zero in a position
		for(int i=0; i<=alphabet.length();i++) {
			postionHolder[i]=-1;
		}

		// the checkArray variable checks every box in the array to see if it repeats
		//it decreases on every box and it has to be -26 in order for it to be written
		// in the postionHolder
		int checkArray=0;

		//w variable adds every time the checkArray is -26 and w is the position of key
		int w=-1;

		while(w<25) {

			double doubleRan=Math.random()*(26);
			int randomNum=(int)doubleRan;

			//checks for a copy of array 
			for(int i=0; i<=25; i++) {
				if(postionHolder[i]!=randomNum) {
					checkArray--;

				}
			}

			//if array doesn't have a copy 
			if(checkArray==-26) {
				w++;
				postionHolder[w]=randomNum;
				//key on position w holds the alphabetChar on positions randomNum char
				key[w]=alphabetChar[randomNum];
			}
			//rests to checkArray again
			checkArray=0;

		}
		//this converts a char to a string 
		String codemsg = new String(key);

		return codemsg;

	}
	public  String encode(String Msg) {
		//this codes the message and returns the message encoded

		//this is the function that creates the alphabet and returns it as a string
		String alphabet=alphabet();

		//converts the string to caps and saves in a new string
		String CapAlphabet=alphabet.toUpperCase();

		//converts the string to caps and saves in a new string
		String Capkey=key.toUpperCase();


		//this converts the string Message to a char array
		char[] encodedCharMsg = Msg.toCharArray();

		for(int i=0; i<Msg.length(); i++) {
			for(int j=0; j<alphabet.length(); j++) {

				//if the message has a cap 
				if(Msg.charAt(i)==CapAlphabet.charAt(j)) {
					//uses the position of the CapAlphabet to get char of the key on that position
					encodedCharMsg[i]=Capkey.charAt(j);

				}
				//if the message is lower case
				else if(Msg.charAt(i)==alphabet.charAt(j)) {
					//uses the position of the alphabet to get char of the key on that position
					encodedCharMsg[i]=key.charAt(j);
				}

			}

		}

		//converts char array to string
		String encodedmsg = new String(encodedCharMsg);

		return encodedmsg;

	}

	public  String decode(String Msg) {	
		//this decodes the message that was sent 

		//alphabet function returns the alphabet as a string
		String alphabet=alphabet();

		//this converts the alphabet to caps and saves it to a string
		String CapAlphabet=alphabet.toUpperCase();

		//this converts the key to caps and saves it to a string
		String Capkey=key.toUpperCase();

		//this converts the string Message to a char array
		char[] decodedCharMsg=Msg.toCharArray();

		for(int i=0; i<Msg.length(); i++) {
			for(int j=0; j<key.length(); j++) {

				// this is if the message is cap
				if(Msg.charAt(i)==Capkey.charAt(j)) {

					//this get the position of Capkey and gets char of position of CapAlphabet
					decodedCharMsg[i]=CapAlphabet.charAt(j);


				}
				//this is if its lower case
				else if(Msg.charAt(i)==key.charAt(j)) {
					//this get the position of key and gets char of position of alphabet
					decodedCharMsg[i]=alphabet.charAt(j);
				}

			}

		}

		//converts char array to string
		String decodedMsg = new String(decodedCharMsg);

		return decodedMsg;

	}

	public String getSymmetricKey() {
		return key;
	}

}


