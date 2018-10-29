package project2;

public class Messenger {

	public static void main(String[] args) {
		String msg1 = "Hello Alice!";
		String msg2 = "Hello Bob!";

		// client provided key
		Encoder bob = new Encoder("hyqjzkrwxtncsoaedbpmvluifg");
		String encodedMsg = bob.encode(msg1);
		System.out.println("Sent: " + encodedMsg);
		Encoder alice = new Encoder("orlqpyzaxdfvtknscgmjwuhibe");
		System.out.println("Received: " + alice.encode(encodedMsg));
		encodedMsg = alice.encode(msg2);
		System.out.println("Sent: " + encodedMsg);
		System.out.println("Received: " + bob.encode(encodedMsg));
		System.out.println("--------------------------------------");

		// randomly generated key
		bob = new Encoder();
		encodedMsg = bob.encode(msg1);
		System.out.println("Sent: " + encodedMsg);
		alice = new Encoder(bob.getSymmetricKey());
		System.out.println("Received: " + alice.encode(encodedMsg));
		encodedMsg = alice.encode(msg2);
		System.out.println("Sent: " + encodedMsg);
		System.out.println("Received: " + bob.encode(encodedMsg));
		System.out.println("--------------------------------------");

		// pad encoder, client provided key
		PadEncoder bobPad = new PadEncoder("hyqjzkrwxtncsoaedbpmvluifg", 3);
		encodedMsg = bobPad.encode(msg1);
		System.out.println("Sent: " + encodedMsg);
		PadEncoder alicePad = new PadEncoder("orlqpyzaxdfvtknscgmjwuhibe", 3);
		System.out.println("Received: " + bobPad.decode(encodedMsg));
		System.out.println("Received: " + alicePad.decode(encodedMsg));
		encodedMsg = alicePad.encode(msg2);
		System.out.println("Sent: " + encodedMsg);
		
		System.out.println("--------------------------------------");

//		// pad encoder, randomly generated key
		bobPad = new PadEncoder(3);
		encodedMsg = bobPad.encode(msg1);
		System.out.println("Sent: " + encodedMsg);
		alicePad = new PadEncoder(bobPad.getSymmetricKey(), 3);
		System.out.println("Received: " + alicePad.decode(encodedMsg));
		encodedMsg = alicePad.encode(msg2);
		System.out.println("Sent: " + encodedMsg);
		System.out.println("Received: " + bobPad.decode(encodedMsg));
		System.out.println("--------------------------------------");
	}

}
