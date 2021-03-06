LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
ENTITY TIMEKEEP IS
	PORT (
		CLK, CLK1 : IN STD_LOGIC;
		M0, M1, S0, S1 : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
		TIMEOUT : OUT STD_LOGIC);
END TIMEKEEP;
ARCHITECTURE BEHAV OF TIMEKEEP IS
BEGIN
	PROCESS (CLK, CLK1, M0, M1, S0, S1)
	BEGIN
		IF (CLK'EVENT AND CLK = '1') THEN
			IF M0 = "0000" AND M1 = "0000" AND S0 = "0000" AND S1 = "0000" THEN
				TIMEOUT <= CLK1;
			END IF;
		END IF;
	END PROCESS;
END BEHAV;