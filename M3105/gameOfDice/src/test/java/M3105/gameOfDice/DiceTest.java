package M3105.gameOfDice;

import static org.junit.Assert.assertTrue;


import java.util.Random;

import org.junit.Test;
import static org.mockito.Mockito.mock; 
import static org.mockito.Mockito.when; 
public class DiceTest {

	
	@Test
	public void rollReturnsAValue() {
		Dice theDice = new Dice(new Random());
		for (int i = 0; i < 100; i++) {
			int result = theDice.roll();
			assertTrue(result >= 1);
			assertTrue(result <= 6);
		}
	}
	
	
	@Test(expected = RuntimeException.class)
 	public void identifyBadValuesGreaterThanNumberOfFaces() {
 		Random randMock = mock(Random.class);
 		when(randMock.nextInt(6)).thenReturn(7);
 		Dice theDice = new Dice(randMock);
 		theDice.roll();
 	}  
	
	@Test(expected = RuntimeException.class)
 	public void identifyBadValuesLesserThanOne() {
		Random randMock = mock(Random.class);
		when(randMock.nextInt(6)).thenReturn(-8);
		Dice theDice = new Dice(randMock);
     	theDice.roll();
 	}
}
