program vijos_1482;

var
   n,i,j,k,o,p,t,l:longint;
   s:string;


procedure px(s:string);
begin
   begin
    l:=length(s);
    for j:=1 to l-3 do
    for k:=j+1 to l-2 do
    for o:=k+1 to l-1 do
    for p:=o+1 to l do
     if ((s[j]=s[k]) and (s[o]=s[p])) or
        ((s[j]=s[p]) and (s[k]=s[o])) then
        begin
         writeln('de1ete');
         exit;
        end;
    writeln('safe');
   end;
end;

begin
 readln(n);

 for i:=1 to n do
      begin
       readln(s);
       px(s);
      end;
end.

