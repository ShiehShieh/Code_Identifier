program test_2;
var
        f:array[0..40,0..6]of qword;
        che,t,i,j,k,n,l,m:longint;
        a:array[1..40]of longint;
        st:string;
function max(x,y:longint):longint;
begin
        if x>y then exit(x)
        else exit(y);
end;
begin
        fillchar(f,sizeof(f),0);
        readln(n,k);
        readln(st);
        while st[length(st)]=' ' do delete(st,length(st),1);
        for i:=n-1 downto k do val(copy(st,i+1,n-i),f[1,i]);
        for i:=1 to k do
          for j:=n-1 downto k-i+1 do
            for l:=n-i+2 downto j+1 do
              begin
                val(copy(st,j+1,l-j),che);
                f[i,j]:=max(f[i,j],f[i-1,l]*che);
              end;
        t:=0;
        for i:=1 to n-k do
          begin
            val(copy(st,1,i),che);
            f[k,i]:=f[k,i]*che;
            if f[k,i]>t then t:=f[k,i];
          end;
        write(t);
 end.

