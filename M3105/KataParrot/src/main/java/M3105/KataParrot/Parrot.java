package M3105.KataParrot;

public class Parrot {

	
	private ParrotTypeEnum type;

	private double voltage;
	private boolean isNailed;

	public Parrot(ParrotTypeEnum _type) {
		this.type = _type;
	
	} 

	public double getSpeed() {
		switch (type) {
		case EUROPEAN:
			throw new RuntimeException("Should be unreachable");
		case AFRICAN: 
			throw new RuntimeException("Should be unreachable");
		case NORWEGIAN_BLUE:
			throw new RuntimeException("Should be unreachable");
		}
		throw new RuntimeException("Should be unreachable");
	}

	

}
