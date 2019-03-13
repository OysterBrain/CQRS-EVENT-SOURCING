package marsRover;

public class PlanetMars {

	private String[][] map;
	
	public PlanetMars(String[][] map) {
		this.map = new String[100][100];
		
		
		for(int i=0; i < 100 ; i++) {
			for(int j= 0; j < 100; j++) {
				map[i][j] = "";
			}
		}
		
	}

	public String[][] getMap() {
		return map;
	}

	public void setMap(String[][] map) {
		this.map = map;
	}
	
	
	
}
