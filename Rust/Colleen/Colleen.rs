/*
    This is a comment
*/

macro_rules! CONTENT {
    () => {
        "/*{1}    This is a comment{1}*/{1}{1}macro_rules! CONTENT {{{1}    () => {{{1}        {2}{0}{2}{1}    }}{1}}}{1}{1}fn print_content() {{{1}    let content_fmt = format!(CONTENT!(), CONTENT!(), 10 as char, 34 as char);{1}    print!({2}{{}}{2}, content_fmt);{1}}}{1}{1}{1}fn main() {{{1}    /*{1}        This is another comment{1}    */{1}    print_content();{1}}}"
    }
}

fn print_content() {
    let content_fmt = format!(CONTENT!(), CONTENT!(), 10 as char, 34 as char);
    print!("{}", content_fmt);
}


fn main() {
    /*
        This is another comment
    */
    print_content();
}