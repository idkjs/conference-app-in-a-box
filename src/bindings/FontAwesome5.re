[@bs.module ("@expo/vector-icons", "FontAwesome5")] [@react.component]
external make:
  (~name: [@bs.string][ | `calendar | `map | `user ], ~size: int, ~color: string, ~style: ReactNative.Style.t=?) =>
  React.element =
  "FontAwesome5";
