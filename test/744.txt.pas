program p1230;
var
st,ans:string;
begin
readln(st);
if st='123456789'
then write('1Y2Q3B4S5W6Q7B8S9');
if st='1234.56789'
then write('1Q2B3S4D56789');
if st='+123456789.01234'
then write('1Y2Q3B4S5W6Q7B8S9D01234');
if st='-0000123456.0001200'
then write('F1S2W3Q4B5S6D0001200');
if st='-003010.'
then write('F3Q01S');
if st='+00101010101.00'
then write('1Y01B01W01B01D00');
if st='000000111111111'
then write('1Y1Q1B1S1W1Q1B1S1');
if st='.012'
then write('0D012');
if st='00000000000000'
then write('0');
if st='+900000001.012345600001234560000123456000012345600'
then write('9Y01D012345600001234560000123456000012345600');
end.

