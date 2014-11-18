program drawing;
var
  pic:array[1..1000,1..1000]of char;
  map,high:array[1..50,1..50]of shortint;
  m,n,i,j,k,l,h:longint;
procedure put(o,p:longint);
  var
    q,w:longint;
  begin
    for q:=o to o+3 do
      for w:=p to p+4 do
        pic[q,w]:=' ';
    for q:=o+1 to o+4 do pic[q,p+5]:=' ';
    for q:=o+2 to o+5 do pic[q,p+6]:=' ';
    for w:=p+1 to p+4 do pic[o+4,w]:=' ';
    for w:=p+2 to P+5 do pic[o+5,w]:=' ';
    pic[o,p]:='+';
    pic[o+3,p]:='+';
    pic[o+5,p+2]:='+';
    pic[o,p+4]:='+';
    pic[o+3,p+4]:='+';
    pic[o+2,p+6]:='+';
    pic[o+5,p+6]:='+';
    for q:=o+1 to o+2 do pic[q,p]:='|';
    for q:=o+1 to o+2 do pic[q,p+4]:='|';
    for q:=o+3 to o+4 do pic[q,p+6]:='|';
    for w:=p+1 to p+3 do pic[o,w]:='-';
    for w:=p+1 to p+3 do pic[o+3,w]:='-';
    for w:=p+3 to p+5 do pic[o+5,w]:='-';
    pic[o+4,p+1]:='/';
    pic[o+4,p+5]:='/';
    pic[o+1,p+5]:='/';
  end;
begin
  readln(m,n);
  k:=0;
  for i:=m downto 1 do
    begin
      for j:=1 to n do
        begin
          read(map[i,j]);
          high[i,j]:=3*map[i,j]+1+2*i;
          if high[i,j]>k then k:=high[i,j];
        end;
      readln;
    end;
  l:=n*4+m*2+1;
  for i:=1 to k do
    for j:=1 to l do
      pic[i,j]:='.';
  for i:=m downto 1 do
    for j:=1 to n do
      for h:=1 to map[i,j] do
        begin
          put((h-1)*3+i*2-1,i*2-5+4*j);
        end;
  for i:=k downto 1 do
    begin
      for j:=1 to l do
        write(pic[i,j]);
      writeln;
    end;
end.
                           
