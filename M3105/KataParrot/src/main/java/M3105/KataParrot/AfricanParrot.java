package M3105.KataParrot;

public class AfricanParrot extends Parrot{
	
	private int numberOfCoconuts ; 
	public AfricanParrot(int numberOfCoconuts) {
		super(ParrotTypeEnum.AFRICAN);
		
		this.numberOfCoconuts=numberOfCoconuts;
	}
	@Override
	public double getSpeed() {

		
		return Math.max(0,getBaseSpeed()-getLoadFactor()*numberOfCoconuts );
	}
	
	public double getBaseSpeed() {
		
		return 12.0;
		
		
	}
	
	public double getLoadFactor() {
		
		return 9.0;
	}
	
	

	
	

}
