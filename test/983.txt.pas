var
  st1,st2:string;
procedure work(st1,st2:string);
var
  len,k:longint;
begin
  if st2<>'' then
    begin
      len:=length(st2);
      k:=pos(st2[len],st1);
      write(st2[len]);
      work(copy(st1,1,k-1),copy(st2,1,k-1));
      work(copy(st1,k+1,len-k),copy(st2,k,len-k));
    end;
end;
begin
  readln(st1);
  readln(st2);
  work(st1,st2);
end.
