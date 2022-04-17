LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
ENTITY KEYPASSWD IS
    PORT (
        CLK : IN STD_LOGIC;
        KEY1, KEY2, KEY3, KEY4 : IN STD_LOGIC;
        KEYWD : OUT STD_LOGIC_VECTOR(3 DOWNTO 0));
END KEYPASSWD;
ARCHITECTURE BEHAVE OF KEYPASSWD IS
BEGIN
    PROCESS (CLK)
    BEGIN
        IF (CLK'EVENT AND CLK = '1') THEN
            IF (KEY1 = '0') THEN
                KEYWD <= "1000";
            ELSIF (KEY2 = '0') THEN
                KEYWD <= "0100";
            ELSIF (KEY3 = '0') THEN
                KEYWD <= "0010";
            ELSIF (KEY4 = '0') THEN
                KEYWD <= "0001";
            ELSE
                KEYWD <= "0000";
            END IF;
        END IF;
    END PROCESS;
END BEHAVE;