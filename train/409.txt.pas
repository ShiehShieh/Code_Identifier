program p1230;

const
  wei:array[1..13] of string[2]=('','S','B','Q','W','S','B','Q','Y','S','B','Q','W');
var
  ts,s,ans:ansistring;
  i,j,k,m,n:longint;
  c:char;

BEGIN

  readln(s);

  if (s[1]='-') or (s[1]='+') then n:=2 else n:=1;

  while not((s[n] in ['1'..'9']) or (s[1]='.')) and (length(s)>1) do begin
    delete(s,n,1);
  end;

  m:=pos('.',s);

  if (m<>0) and (m<>length(s)) then begin
    ans:='D';
    ans:=ans+copy(s,m+1,length(s)-m);
  end;

  if m=1 then begin
    ans:='0'+ans;
    writeln(ans);
    
    halt;
  end;

  if m=0 then m:=length(s)+1;

  for i:=m-1 downto 1 do begin
    case s[i] of
      '0':begin
        ans:='0'+ans;
      end;
      '1'..'9':begin
        ans:=wei[m-i]+ans;
        ans:=s[i]+ans;

      end;
      '-':begin
        ans:='F'+ans;
      end;
    end;
  end;

  if m=length(s) then begin
    while ans[length(ans)]='0' do delete(ans,length(ans),1);
  end;

  n:=pos('D',ans);

  for i:=n downto 2 do begin
    if (ans[i] in ['A'..'Z']) and (ans[i-1]='0') then
      delete(ans,i-1,1);
  end;

  n:=pos('D',ans);

  for i:=n downto 2 do
    if (ans[i]='0') and (ans[i-1]='0') then
      delete(ans,i-1,1);
  writeln(ans);

END.

