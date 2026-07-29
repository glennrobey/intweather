import { useEffect, useRef, useState } from "react";

interface SearchBarProps {
  city: string;
  setCity: (city: string) => void;
  onSearch: () => void;
  suggestions: string[] | null;
  onSelectSuggestion: (city: string) => void;
}

function SearchBar({
  city,
  setCity,
  onSearch,
  suggestions,
  onSelectSuggestion,
}: SearchBarProps) {
  const [showSuggestions, setShowSuggestions] = useState(false);
  const [selectedIndex, setSelectedIndex] = useState(-1);

  const searchRef = useRef<HTMLDivElement>(null);

  // Close suggestions when clicking outside
  useEffect(() => {
    function handleClickOutside(event: MouseEvent) {
      if (
        searchRef.current &&
        !searchRef.current.contains(event.target as Node)
      ) {
        setShowSuggestions(false);
        setSelectedIndex(-1);
      }
    }

    document.addEventListener("mousedown", handleClickOutside);

    return () => {
      document.removeEventListener("mousedown", handleClickOutside);
    };
  }, []);

  return (
    <div ref={searchRef} className="relative flex gap-3">
      <input
        className="
    rounded-full
    px-5
    py-3
    bg-black/30
    backdrop-blur-xl
    border
    border-white/20
    text-white
    outline-none
  "
        value={city}
        onChange={(e) => {
          setCity(e.target.value);
          setShowSuggestions(true);
          setSelectedIndex(-1);
        }}
        onKeyDown={(e) => {
          const results = suggestions ?? [];

          if (e.key === "ArrowDown") {
            e.preventDefault();

            setSelectedIndex((prev) =>
              prev < results.length - 1 ? prev + 1 : prev,
            );
          }

          if (e.key === "ArrowUp") {
            e.preventDefault();

            setSelectedIndex((prev) => (prev > 0 ? prev - 1 : prev));
          }

          if (e.key === "Enter") {
            if (selectedIndex >= 0) {
              setShowSuggestions(false);
              onSelectSuggestion(results[selectedIndex]);
            } else {
              setShowSuggestions(false);
              onSearch();
            }
          }

          if (e.key === "Escape") {
            setShowSuggestions(false);
            setSelectedIndex(-1);
          }
        }}
        placeholder="Search city..."
      />

      <button
        className="
          rounded-full
          px-6
          bg-gray-500
          text-white
          hover:bg-black
          transition
          duration-300
          ease-in-out
          hover:scale-115
        "
        onClick={() => {
          setShowSuggestions(false);
          onSearch();
        }}
      >
        Search
      </button>

      {showSuggestions && suggestions && suggestions.length > 0 && (
        <div
          className="
            absolute
            top-14
            left-0
            w-full
            bg-black/70
            backdrop-blur-lg
            border
            border-white/20
            rounded-2xl
            overflow-hidden
            shadow-xl
            z-10
          "
        >
          {suggestions.map((suggestion, index) => (
            <button
              key={`${suggestion}-${index}`}
              className={`
                block
                w-full
                text-left
                px-5
                py-3
                text-white
                transition
                ${selectedIndex === index ? "bg-white/20" : "hover:bg-white/20"}
              `}
              onClick={() => {
                setShowSuggestions(false);
                setSelectedIndex(-1);
                onSelectSuggestion(suggestion);
              }}
            >
              {suggestion}
            </button>
          ))}
        </div>
      )}
    </div>
  );
}

export default SearchBar;
