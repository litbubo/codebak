LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
ENTITY STATECYCLE IS
    PORT (
        CLK : IN STD_LOGIC;
        CYCOUT : OUT STD_LOGIC_VECTOR(2 DOWNTO 0));
END STATECYCLE;
ARCHITECTURE BEHA OF STATECYCLE IS
    TYPE STATE IS(S0, S1, S2, S3, S4, S5, S6, S7);
    SIGNAL CURRENT_STATE : STATE;
BEGIN
    PROCESS (CLK)
    BEGIN
        IF CLK'EVENT AND CLK = '1' THEN
            CASE CURRENT_STATE IS
                WHEN S0 =>
                    CYCOUT <= "000";
                    CURRENT_STATE <= S1;
                WHEN S1 =>
                    CYCOUT <= "001";
                    CURRENT_STATE <= S2;
                WHEN S2 =>
                    CYCOUT <= "010";
                    CURRENT_STATE <= S3;
                WHEN S3 =>
                    CYCOUT <= "011";
                    CURRENT_STATE <= S4;
                WHEN S4 =>
                    CYCOUT <= "100";
                    CURRENT_STATE <= S5;
                WHEN S5 =>
                    CYCOUT <= "101";
                    CURRENT_STATE <= S6;
                WHEN S6 =>
                    CYCOUT <= "110";
                    CURRENT_STATE <= S7;
                WHEN S7 =>
                    CYCOUT <= "111";
                    CURRENT_STATE <= S0;
            END CASE;
        END IF;
    END PROCESS;
END BEHA;