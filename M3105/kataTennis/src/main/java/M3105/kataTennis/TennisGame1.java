package M3105.kataTennis;

public class TennisGame1 implements TennisGame {

	private int scorePlayer1 = 0;
	private int scorePlayer2 = 0;
	private String player1Name;
	private String player2Name;

	public TennisGame1(String player1Name, String player2Name) {
		this.setPlayer1Name(player1Name);
		this.setPlayer2Name(player2Name);
	}

	public void wonPoint(String playerName) {
		if (playerName == "player1")
			scorePlayer1 += 1;
		else
			scorePlayer2 += 1;
	}

	public String getScore() {
		String score = "";
		String end = "-All";
		int tempScore = 0;
		if (scoreEquals()) {
			switchParametrable(score, scorePlayer1, end);
		} else if (scoreSup4()) {
			int minusResult = scorePlayer1 - scorePlayer2;
			score = affichageAvantage(minusResult);
		} else {
			end = "";
			for (int i = 1; i < 3; i++) {
				if (i == 1)
					tempScore = scorePlayer1;
				else {
					score += "-";
					tempScore = scorePlayer2;
				}
				score = switchParametrable(score, tempScore,end);
			}
		}
		return score;
	}

	private String switchParametrable(String score, int tempScore, String end) {
		switch (tempScore) {
		case 0:
			score += "Love"+end;
			break;
		case 1:
			score += "Fifteen"+end;
			break;
		case 2:
			score += "Thirty"+end;
			break;
		case 3:
			score += "Forty"+end;
			break;
		default:
			score += "Deuce"+end;
			break;
		}
		return score;
	}

	private String affichageAvantage(int minusResult) {
		String score;
		if (minusResult == 1)
			score = "Advantage player1";
		else if (minusResult == -1)
			score = "Advantage player2";
		else if (minusResult >= 2)
			score = "Win for player1";
		else
			score = "Win for player2";
		return score;
	}

	private boolean scoreSup4() {
		return scorePlayer1 >= 4 || scorePlayer2 >= 4;
	}

	private boolean scoreEquals() {
		return scorePlayer1 == scorePlayer2;
	}

	public String getPlayer2Name() {
		return player2Name;
	}

	public void setPlayer2Name(String player2Name) {
		this.player2Name = player2Name;
	}

	public String getPlayer1Name() {
		return player1Name;
	}

	public void setPlayer1Name(String player1Name) {
		this.player1Name = player1Name;
	}

}
