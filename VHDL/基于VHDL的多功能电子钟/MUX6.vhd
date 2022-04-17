LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
ENTITY MUX6 IS
    PORT (
        NUM0, NUM1, NUM2, NUM3, NUM4, NUM5 : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
        SEL : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
        MUX6OUT : OUT STD_LOGIC_VECTOR(3 DOWNTO 0));
END MUX6;
ARCHITECTURE BEHAV OF MUX6 IS
    SIGNAL Y : STD_LOGIC_VECTOR(3 DOWNTO 0);
BEGIN
    PROCESS (SEL)
    BEGIN
        CASE SEL IS
            WHEN "000" => Y <= NUM0;
            WHEN "001" => Y <= NUM1;
            WHEN "010" => Y <= "1111";
            WHEN "011" => Y <= NUM2;
            WHEN "100" => Y <= NUM3;
            WHEN "101" => Y <= "1111";
            WHEN "110" => Y <= NUM4;
            WHEN "111" => Y <= NUM5;
            WHEN OTHERS => Y <= "XXXX";
        END CASE;
        MUX6OUT <= Y;
    END PROCESS;
END BEHAV;