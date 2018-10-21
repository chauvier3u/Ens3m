package TP_3;

import java.awt.AWTException;
import java.awt.Robot;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;

public class exercice_4
{
	/**
	 * @param args
	 * @throws AWTException
	 */
	public static void ouvrir_paint(Robot R1) throws AWTException

	{
		R1.keyPress(KeyEvent.VK_WINDOWS);
		R1.delay(10);
		R1.keyRelease(KeyEvent.VK_WINDOWS);
		R1.delay(500);

		R1.keyPress(KeyEvent.VK_P);
		R1.delay(10);
		R1.keyRelease(KeyEvent.VK_P);
		R1.delay(100);
		R1.keyPress(KeyEvent.VK_A);
		R1.delay(10);
		R1.keyRelease(KeyEvent.VK_A);
		R1.delay(100);
		R1.keyPress(KeyEvent.VK_I);
		R1.delay(10);
		R1.keyRelease(KeyEvent.VK_I);
		R1.delay(100);
		R1.keyPress(KeyEvent.VK_N);
		R1.delay(10);
		R1.keyRelease(KeyEvent.VK_N);
		R1.delay(100);
		R1.keyPress(KeyEvent.VK_T);
		R1.delay(10);
		R1.keyRelease(KeyEvent.VK_T);
		R1.delay(100);
		R1.keyPress(KeyEvent.VK_ENTER);
		R1.delay(10);
		R1.keyRelease(KeyEvent.VK_ENTER);
		R1.delay(2500);
	}

	public static void fermer_paint(Robot R1) throws AWTException
	{
		R1.delay(20);
		R1.mouseMove(1340, 10);
		R1.delay(5000);
		R1.mousePress(InputEvent.BUTTON1_DOWN_MASK);
		R1.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
		R1.delay(50);
		R1.mouseMove(680, 380);
		R1.delay(100);
		R1.mousePress(InputEvent.BUTTON1_DOWN_MASK);
		R1.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
		R1.delay(50);
	}

	public static void selection_crayon(Robot R1, int temps) throws AWTException
	{
		R1.mouseMove(324, 70);
		R1.mousePress(InputEvent.BUTTON1_DOWN_MASK);
		R1.delay(temps);
		R1.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
		R1.delay(temps);
	}

	public static void selection_pot_peinture(Robot R1, int temps) throws AWTException
	{
		R1.mouseMove(344, 70);
		R1.mousePress(InputEvent.BUTTON1_DOWN_MASK);
		R1.delay(temps);
		R1.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
		R1.delay(temps);
	}

	public static void niveau1(Robot R1, int x0, int y0, int temps) throws AWTException
	{
		ouvrir_paint(R1);
		selection_crayon(R1, temps);

		R1.mouseMove(x0, y0);
		R1.delay(temps);
		R1.mousePress(InputEvent.BUTTON1_DOWN_MASK);
		R1.delay(temps);
		R1.mouseMove(x0 + 50, y0 + 50);
		R1.delay(temps);
		R1.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
		R1.delay(temps);
	}

	public static void niveau2(Robot R1, int x0, int y0, int temps) throws AWTException
	{
		ouvrir_paint(R1);
		selection_crayon(R1, temps);

		R1.mouseMove(x0, y0);
		R1.mousePress(InputEvent.BUTTON1_DOWN_MASK);
		R1.delay(temps);
		R1.mouseMove(x0 + 40, y0);
		R1.delay(temps);
		R1.mouseMove(x0 + 40, y0 + 40);
		R1.delay(temps);
		R1.mouseMove(x0, y0 + 40);
		R1.delay(temps);
		R1.mouseMove(x0, y0);
		R1.delay(temps);
		R1.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
		R1.delay(temps);
	}

	public static void niveau3(Robot R1, int x0, int y0, int temps) throws AWTException
	{
		niveau2(R1, x0, y0, temps);
		R1.mousePress(InputEvent.BUTTON1_DOWN_MASK);
		R1.delay(temps);
		R1.mouseMove(x0 - 40, y0);
		R1.delay(temps);
		R1.mouseMove(x0 - 40, y0 + 40);
		R1.delay(temps);
		R1.mouseMove(x0, y0 + 40);
		R1.delay(temps);
		R1.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
		R1.delay(temps);

		selection_pot_peinture(R1, temps);
		R1.mouseMove(x0 + 20, y0 + 20);
		R1.delay(temps);
		R1.mousePress(InputEvent.BUTTON1_DOWN_MASK);
		R1.delay(temps);
		R1.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
		R1.delay(temps);
	}

	public static void niveau4(Robot R1, int x0, int y0, int temps) throws AWTException
	{
		ouvrir_paint(R1);
		selection_crayon(R1, temps);
		for (int i = 0; i < 9; i++)
		{
			R1.mouseMove(x0 + i * 40, y0);
			R1.delay(temps);
			R1.mousePress(InputEvent.BUTTON1_DOWN_MASK);
			R1.delay(temps);
			R1.mouseMove(x0 + i * 40, y0 + 8 * 40);
			R1.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
			R1.delay(temps);

			R1.mouseMove(x0, y0 + i * 40);
			R1.delay(temps);
			R1.mousePress(InputEvent.BUTTON1_DOWN_MASK);
			R1.delay(temps);
			R1.mouseMove(x0 + 8 * 40, y0 + i * 40);
			R1.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
			R1.delay(temps);

		}
	}

	public static void niveau5(Robot R1, int x0, int y0, int temps) throws AWTException
	{
		niveau4(R1, x0, y0, temps);
		selection_pot_peinture(R1, temps);

		for (int j = 0; j < 8; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				if (j % 2 == 0)
				{
					R1.mouseMove(x0 + 20 + i * 80, y0 + 20 + j * 40);
					R1.delay(temps);
					R1.mousePress(InputEvent.BUTTON1_DOWN_MASK);
					R1.delay(temps);
					R1.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
					R1.delay(temps);
				}
				else
				{
					R1.mouseMove(x0 + 60 + i * 80, y0 + 20 + j * 40);
					R1.delay(temps);
					R1.mousePress(InputEvent.BUTTON1_DOWN_MASK);
					R1.delay(temps);
					R1.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
					R1.delay(temps);
				}
			}
		}
	}

	public static void main(String[] args) throws AWTException
	{
		int x0 = 500;
		int y0 = 200;
		int temps = 10;
		Robot R1 = new Robot();

		/*
		 * niveau1(R1, x0, y0, temps); fermer_paint(R1); niveau2(R1, x0, y0, temps);
		 * fermer_paint(R1); niveau3(R1, x0, y0, temps); fermer_paint(R1); niveau4(R1,
		 * x0, y0, temps); //fermer_paint(R1);
		 */niveau5(R1, x0, y0, temps);
		fermer_paint(R1);
		R1.mouseMove(0, 0);

	}
}