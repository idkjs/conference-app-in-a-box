open ReactNative;
open ReactNavigation;

open PagerStyle;

[@react.component]
let make = (~navigation: Navigation.t) => {
  let (index, setIndex) = React.useState(() => 0);

  let updateIndex = newIndex => {
    setIndex(newIndex);
  };
  <View style=styles##container>
    <View style=styles##tabContainer>
      <TouchableHighlight
        underlayColor="transparent"
        style=styles##buttonContainer
        onPress={_ => updateIndex(_ => 0)}>
        <View
          style=Style.(
            arrayOption([|
              Some(styles##button),
              index == 0
                ? Some(styles##indexSelected)
                : Some(styles##indexNotSelected),
            |])
          )>
          <Text style=styles##buttonText> {"Talk Info" |> React.string} </Text>
        </View>
      </TouchableHighlight>
      <TouchableHighlight
        underlayColor="transparent"
        style=styles##buttonContainer
        onPress={_ => updateIndex(_ => 1)}>
        <View
          style=Style.(
            arrayOption([|
              Some(styles##button),
              index == 1
                ? Some(styles##indexSelected)
                : Some(styles##indexNotSelected),
            |])
          )>
          <Text style=styles##buttonText> {"Discuss" |> React.string} </Text>
        </View>
      </TouchableHighlight>
    </View>
    {switch (index) {
     | 0 => <Talk navigation />
     | 1 => <Discussion navigation />
     | _ => React.null
     }}
  </View>;
};

make->NavigationOptions.setDynamicNavigationOptions(params => {
  let navigation = params##navigation;
  let title = navigation
  ->Navigation.getParam("talk")
  ->Js.Nullable.toOption
  ->Belt.Option.mapWithDefault("Talk", t => t##name);

  NavigationOptions.t(
    ~title,
    ~headerTintColor=Theme.Colors.highlight,
    (),
  );
});