[@bs.module ("@expo/vector-icons", "Ionicons")] [@react.component]
external make:
  (~name: string, ~size: int, ~color: string, ~style: ReactNative.Style.t=?) =>
  React.element =
  "Ionicons";