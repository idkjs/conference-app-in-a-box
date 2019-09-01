open ReactNative;
[@react.component]
let make = (~authState=?) => {
  let render =
    switch (authState) {
    | Some(auth) =>
      Js.log(auth);
      <Text> {React.string(auth ++ " auth state")} </Text>;
    | None =>
      Js.log("None");
      <Text> {React.string("no auth state")} </Text>;
    };

  <View> <Text> {React.string("TEST Screen")} </Text> render </View>;
};
