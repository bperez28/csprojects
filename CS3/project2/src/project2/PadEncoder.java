package project2;


public class PadEncoder {
	private int padNum;
	private String key="";

	public PadEncoder(String string, int pad) {
		//pad number and key are provided
		padNum=pad;
		key=string;

	}

	public PadEncoder(int pad) {
		//pad number and key is generated by randomgen() from other class
		padNum=pad;
		//Encoder.randomgen() returns string of a key randomized 
		key=Encoder.randomgen();

	}

	public String decode(String encodedMsg) {
		//encodedmsg is given this returns it decoded

		//creates char array from encodedMsg
		char[] charEncodedmsg= encodedMsg.toCharArray();
		//creates a new char array to hold the decoded message with out the pad
		char[ ] encodedMsgNoPad = new char[encodedMsg.length()];
		int j=0;
		int w=0;
		//this loop gets out when j equals the length  divided by how many pads are added
		while(j<=encodedMsg.length()/(padNum+1)-1) {
			//stores chars to char array without pads 
			encodedMsgNoPad[w]=charEncodedmsg[j*(padNum+1)];

			j++;	
			w++;
		}

		//makes encodedMsg into a string without the pad
		String NewEncodedMsg= new String(encodedMsgNoPad);
		//sets the key to store in Encoder class
		Encoder stringmsg=new Encoder(key);
		//gets the decoded message from the function decode from Encoder class 
		String uncodedmsg=stringmsg.decode(NewEncodedMsg);

		return uncodedmsg;
	}

	public String encode(String Msg) {



		//0 col has 26 rows
		//Encoder.alphabet() returns the string of an alphabet
		String alphabetPad=Encoder.alphabet();
		final int pada=0;

		//1 col has 26 rows
		//converts alphabetPad to all caps and saves in a string
		String CapAlphabetPad=alphabetPad.toUpperCase();
		final int padA=1;

		//2 col has 9 rows 

		//makes 0-9 into a string 
		String charnumbers="";
		for(char c='0'; c<='9'; c++) {
			charnumbers+=c;
		}
		//converts string to char array
		char[] numbersPad=charnumbers.toCharArray();
		final int padnum=2;

		//this hold the key into encoder from other class
		Encoder stringmsg=new Encoder(key);

		//encode is calls by the key and is also given the message to return the encoded message
		String encodedmsg=stringmsg.encode(Msg);

		//creates a new char array with length of the original multiplied by number of pads being added
		char[ ] padedcode = new char[encodedmsg.length()*(padNum+1)+1];

		//j is the position of coded message 
		int j=0;

		for(int i=0; j<=encodedmsg.length()-1;i++) {
			//if the position doesn't need a pad 
			if(i%(padNum+1)==0) {

				padedcode[i]=encodedmsg.charAt(j);
				j++;


			}
			else {

				//this randomizes the cols to use for the switch
				double doublecol= Math.random()*3;
				int cols=(int) doublecol;

				//this randomizes the row of both cap and lower case alphabet 
				double abclengthrow=Math.random()*26;
				int abclengthrows=(int) abclengthrow;

				//this randomizes the row of numbers 
				double numrow=Math.random()*9;
				int numrows=(int) numrow;

				//cols 0-2
				switch(cols) {
				//col 0, row0
				case pada:  padedcode[i]=alphabetPad.charAt(abclengthrows);
				break;
				//col 1, row1
				case padA:  padedcode[i]=CapAlphabetPad.charAt(abclengthrows);
				break;
				//col 2, row2
				case padnum: padedcode[i]=numbersPad[numrows];
				break;
				default: 
					break;

				}

			}
		}
		//converts char array to string
		String EncodedmsgWithPad= new String(padedcode);

		return EncodedmsgWithPad;

	}

	public String getSymmetricKey() {
		return key;
	}

}
