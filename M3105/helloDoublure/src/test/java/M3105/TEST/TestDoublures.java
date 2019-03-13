package M3105.TEST;

import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static org.mockito.Mockito.mock;  
import static org.mockito.Mockito.when;
import static org.mockito.Mockito.verify;  
import static org.mockito.Mockito.times;

public class TestDoublures {

	@Test
	public void test_UnPremierStub() {

		User user = mock(User.class);
		when(user.getLogin()).thenReturn("alice");
		System.out.println(user.getLogin());
		
		 assertEquals(user.getLogin(), "alice");
		// assertEquals(user.getLogin(), "bob");
		}
	
	 @Test
	 public void test_UnPremierMock() {

		User user = mock(User.class);
		when(user.getLogin()).thenReturn("alice");
		System.out.println(user.getLogin());
	    System.out.println(user.getLogin());
	    verify(user, times(2)).getLogin();
	 
		}
	
}
