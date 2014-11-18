program word;
var s:string;
    c:array['a'..'z']of integer;
    ch:char;
    maxn,minn,i,l,k:integer;
    t:boolean;

begin
  readln(s);
  l:=length(s);
  fillchar(c,sizeof(c),0);
  for i:=1 to l do inc(c[s[i]]);

  maxn:=0;
  minn:=200;
  for ch:='a' to 'z' do
    if c[ch]>maxn then maxn:=c[ch];
  for ch:='a' to 'z' do
    if (c[ch]<minn) and (c[ch]<>0) then minn:=c[ch];
  k:=maxn-minn;

  if (k<=1) then t:=false
  else
    begin
      t:=true;
      for i:=2 to trunc(sqrt(k)) do
        if k mod i=0 then
          begin
            t:=false;
            break;
          end;
    end;

  if t=true then
    begin
      writeln('Lucky Word');
      writeln(k)
    end
  else
    begin
      writeln('No Answer');
      writeln(0);
    end;

end.
