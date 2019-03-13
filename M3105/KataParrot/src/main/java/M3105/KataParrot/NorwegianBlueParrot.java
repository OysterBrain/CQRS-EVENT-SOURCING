package M3105.KataParrot;

public class NorwegianBlueParrot extends Parrot {

	private double voltage; 
	private boolean isNailed;
	
	public NorwegianBlueParrot(double voltage , boolean isNailed ) {
		
		super(ParrotTypeEnum.NORWEGIAN_BLUE);
		this.voltage=voltage;
		this.isNailed=isNailed;
		
	}
	
	private double getBaseSpeed(double voltage){
		if(isNailed) {
			return Math.min(24.0, voltage * getBaseSpeed());
		}
		else {
			return 0.0;
		}
		
	}
	private double getBaseSpeed() {
		
		return 12.0;
	}
	
}
